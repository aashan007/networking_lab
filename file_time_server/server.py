import socket
import datetime

now = datetime.datetime.now()
port = 60000                   
s = socket.socket()            
host = socket.gethostname()     
s.bind((host, port))            
s.listen(5)                     
print 'Server listening....'
while True:
    conn, addr = s.accept()     
    print 'Got connection from', addr
    data = conn.recv(1024)
    print('Server received', repr(data))
    filename='mytext.txt'
    f = open('1.txt','rb')
    l = f.read(1024)
    while (l):
       conn.send(l)
       print('Sent ',repr(l))
       l = f.read(1024)
    f.close()
    l=[]
    l.append(now.hour)
    l.append(now.minute)
    l.append(now.second)
    str1=':'.join(str(x) for x in l)
    conn.send(str1)
    print('Done sending')
    conn.close()