import sys

import docker
from flask import Flask

app = Flask(__name__)


def make_stats():
    client = docker.from_env()
    containers = client.containers.list(all=True)

    html_rows = ""
    for container in containers:
        color = "#0f0" if container.status == "running" else "#f00"
        html_rows += f"""
        <tr>
            <td style="padding:10px; border:1px solid #333;">{container.name}</td>
            <td style="padding:10px; border:1px solid #333; color:{color};">{container.status}</td>
            <td style="padding:10px; border:1px solid #333;">{container.image.tags[0] if container.image.tags else "N/A"}</td>
        </tr>
        """
    return html_rows

    return html_rows


@app.route("/")
def home():
    try:
        rows = make_stats()
    except Exception as e:
        rows = f"<tr><td colspan='3'>Error connecting to Docker socket: {e}</td></tr>"

    return f"""
    <html>
    <body style="font-family:monospace; background:#000; color:#0f0; padding:40px;">
        <h1>[ INCEPTION_MONITOR ]</h1>
        <table style="width:100%; border-collapse:collapse; text-align:left;">
            <thead>
                <tr style="border-bottom:2px solid #0f0;">
                    <th style="padding:10px;">Container</th>
                    <th style="padding:10px;">Status</th>
                    <th style="padding:10px;">Image</th>
                </tr>
            </thead>
            <tbody>
                {rows}
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
