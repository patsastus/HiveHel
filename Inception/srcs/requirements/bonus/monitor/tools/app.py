import sys

import docker
from flask import Flask

app = Flask(__name__)


def make_stats():
    client = docker.from_env()
    containers = client.containers.list(all=True)

    rows = ""
    for container in containers:
        try:
            stats = container.stats(stream=False)
            cpu_stats = stats["cpu_stats"]
            precpu_stats = stats["precpu_stats"]
            cpu_delta = (
                cpu_stats["cpu_usage"]["total_usage"]
                - precpu_stats["cpu_usage"]["total_usage"]
            )
            system_delta = (
                cpu_stats["system_cpu_usage"] - precpu_stats["system_cpu_usage"]
            )
            cpu_pct = 0.0
            if system_delta > 0.0 and cpu_delta > 0.0:
                cpu_pct = (
                    (cpu_delta / system_delta) * cpu_stats.get("online_cpus", 1) * 100.0
                )

            mem_usage = stats["memory_stats"]["usage"] - stats["memory_stats"].get(
                "stats", {}
            ).get("inactive_file", 0)
            mem_limit = stats["memory_stats"]["limit"]
            mem_mb = mem_usage / (1024 * 1024)
            mem_pct = (mem_usage / mem_limit) * 100.0

            rows += f"""
            <tr>
                <td style="padding:10px; border-bottom:1px solid #333;">{container.name}</td>
                <td style="padding:10px; border-bottom:1px solid #333; color:#0f0;">{container.status}</td>
                <td style="padding:10px; border-bottom:1px solid #333;">{cpu_pct:.2f}%</td>
                <td style="padding:10px; border-bottom:1px solid #333;">{mem_mb:.1f} MB ({mem_pct:.1f}%)</td>
            </tr>
            """
        except Exception as e:
            rows += (
                f"<tr><td colspan='4'>Error fetching {container.name}: {e}</td></tr>"
            )

    return rows


@app.route("/")
def home():
    return f"""
    <html>
        <head>
            <meta http-equiv="refresh" content="5">
            <style>
                body {{ font-family: 'Courier New', monospace; background: #000; color: #0f0; padding: 50px; }}
                table {{ width: 100%; border-collapse: collapse; margin-top: 20px; }}
                th {{ text-align: left; color: #555; border-bottom: 2px solid #0f0; padding: 10px; }}
                .header {{ color: #0f0; font-weight: bold; border-bottom: 1px solid #0f0; padding-bottom: 10px; }}
            </style>
        </head>
        <body>
            <div class="header">
                <h1>[ Inception Monitor ]</h1>
                <p> Refresh Rate: 5s</p>
            </div>
            <table>
                <thead>
                    <tr>
                        <th>CONTAINER</th>
                        <th>STATUS</th>
                        <th>CPU LOAD</th>
                        <th>MEMORY </th>
                    </tr>
                </thead>
                <tbody>
                    {make_stats()}
                </tbody>
            </table>
        </body>
    </html>
    """


if __name__ == "__main__":
    port_arg = 5000
    if "--port" in sys.argv:
        port_arg = int(sys.argv[sys.argv.index("--port") + 1])
    app.run(host="0.0.0.0", port=port_arg)
