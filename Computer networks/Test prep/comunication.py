###############################################################################
# The communication module (communication.py)
###############################################################################
import pickle
import socket
import struct

codePickle = pickle.dumps
decodePickle = pickle.loads


def send(channel, *args):
    buf = codePickle(args)
    value = socket.htonl(len(buf))
    size = struct.pack("L", value)
    channel.send(size)
    channel.send(buf)


def receive(channel):
    size = struct.calcsize("L")
    size = channel.recv(size)
    try:
        size = socket.ntohl(struct.unpack("L", size)[0])
    except struct.error as e:
        return ''

    buf = ""

    while len(buf) < size:
        buf = channel.recv(size - len(buf))

    return decodePickle(buf)[0]