#!/bin/sh
pass=$(cat /run/secrets/ftp_user_pw)
startPort=${FTP_RANGE_START}
endPort=${FTP_RANGE_END}

if [ ${startPort} -ge ${endPort} ]; then
    echo "startport larger than endport, failing..."
    exit 1
fi

sed -i "s/^pasv_min_port=.*/pasv_min_port=${startPort}/" /etc/vsftpd/vsftpd.conf
sed -i "s/^pasv_max_port=.*/pasv_max_port=${endPort}/" /etc/vsftpd/vsftpd.conf
sed -i "s|^local_root=.*|local_root=${FTP_PATH}|" /etc/vsftpd/vsftpd.conf


if ! id -u "${FTP_USER}" >/dev/null 2>&1; then
    adduser -D -u 1000 "${FTP_USER}"
    echo "${FTP_USER}:${pass}" | chpasswd
    mkdir -p ${FTP_PATH}
    chown -R "${FTP_USER}:${FTP_USER}" ${FTP_PATH}
    chmod -R 755 ${FTP_PATH}
fi

echo "Starting ftp server..."
exec vsftpd /etc/vsftpd/vsftpd.conf
