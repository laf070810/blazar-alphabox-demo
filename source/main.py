from machine import UART
uart = UART(0, 115200)                         # init with given baudrate
uart.init(115200, bits=8, parity=None, stop=1) # init with given parameters

def connect_ap(ssid, password):
    import network

    sta_if = network.WLAN(network.STA_IF)
    sta_if.active(True)
    if sta_if.isconnected():
        sta_if.disconnect()
        
    sta_if.connect(ssid, password)
    while not sta_if.isconnected():
        pass

def disconnect_ap():
    import network
    sta_if = network.WLAN(network.STA_IF)
    sta_if.disconnect()

def mqtt_serial(broker='test.mosquitto.org', topic='blazar/laf/client'):
    import uos
    uos.dupterm(None, 1) # disable REPL on UART(0)

    from umqtt.simple import MQTTClient
    c = MQTTClient('umqtt_client', broker)
    c.set_callback(mqtt_callback)
    c.connect()
    c.subscribe(topic)
    while True:
        c.check_msg()

        if uart.any() != 0:
            len = uart_read(uart, 1)[0]
            buf = uart_read(uart, len)
            c.publish('blazar/laf/server', buf)
    c.disconnect()

def mqtt_callback(topic, msg):
    global uart
    print((topic, msg))
    uart.write(bytes([len(msg)]) + msg)

def uart_read(uart, len):
    buf = b''
    while len != 0:
        c = uart.read(1)
        if c is not None:
            buf += c
            len -= 1
            #print(len)
    return buf

##    import socket
##    addr = socket.getaddrinfo('0.0.0.0', 80)[0][-1]
##
##    s = socket.socket()
##    s.bind(addr)
##    s.listen(1)
##    print('listening')
##    cl, addr = s.accept()
##    print('accepting')
##    cl_file = cl.makefile('rwb', 0)
##    
##    while True:
##        line = cl_file.readline()
##        #if not line or line == b'\r\n':
##        #    break
##        print(line)
##        uart.write(line)
##        #response = uart.readline()
##        #cl.send(response)
##        #cl.close()
