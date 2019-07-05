import sys
import socket

DEFAULT_HOST = ''
DEFAULT_PORT = 1339

def main(argc, argv):    
    port = DEFAULT_PORT
    if (len(sys.argv) >= 2):
        try:
            port = int(sys.argv[1])
        except:
            pass
    
    singleConnect = '-s' in argv[1:]

    try:
        try:
            s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
            s.bind(('', port))
            s.listen()

            while True:
                print(f"Waiting for connection on port {port}")
                c, addr = s.accept()

                print(f"Connected to {str(addr[0])}:{str(addr[1])}")
                print("-------------------------------------")

                while True:
                    data = c.recv(1024) 
                    if not data:
                        if singleConnect:
                            sys.exit()
                        print("-------------------------------------")
                        break
                    print(data.decode('utf-8'), end='')

        except KeyboardInterrupt:
            pass

        s.close()
    
    except Exception as e:
        print(str(e))


if __name__ == '__main__':
    main(len(sys.argv), sys.argv)