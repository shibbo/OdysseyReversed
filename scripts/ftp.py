# ftp.py
# Automatically uploads the NSO and IPS patches to the switch via FTP

import sys
import os
import ftplib

ftp_host = '10.0.0.141'
ftp_port = 5000
ftp_usr = ''
ftp_pwd = ''
ftp_exefs = '/atmosphere/titles/0100000000010000/exefs/'
ftp_exefs_patches = '/atmosphere/exefs_patches/odyssey/'

def do_connect(nso_path, ips_path):
    print("Attempting connection...")

    try:
        ftp = ftplib.FTP()
        ftp.connect(ftp_host, ftp_port)
    except Exception as e:
        print('Connecting failed: %s' % str(e))
        sys.exit(1)
    
    print("Connected!")

    if ftp_usr != '':
        try:
            print ("Logging in...")
            ftp.login(ftp_usr, ftp_pwd)
        except:
            print("Login failed.")
            sys.exit(1)

    nso_file = open(nso_path, 'rb')
    ftp.storbinary("STOR " + ftp_exefs + nso_path, nso_file)

    print("Stored subsdk1 NSO...")

    ips_file = open(ips_path, 'rb')
    ftp.storbinary("STOR " + ftp_exefs_patches + ips_path, ips_file)

    print("Stored IPS...")

    ftp.quit()

    print("Done!")