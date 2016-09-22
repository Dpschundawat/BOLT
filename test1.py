import requests
import time
def main():
    Ledon()
    Proximity_sensor()
    Analog_sensor()
    pwm()
    serialcommunication()
    
#LED CONTROL
def Ledon():
    r = requests.get('http://192.168.2.11/digitalWrite?pin=0&state=HIGH')
    time.sleep(2)
    print(r.json())
    r = requests.get('http://192.168.2.11/digitalWrite?pin=0&state=LOW')
    print(r.json())
    

#Proximity sensor
def Proximity_sensor():
    r = requests.get('http://192.168.2.11/digitalRead?pin=4')
    print(r.json())
    

#Analog sensor
def Analog_sensor():
    r = requests.get('http://192.168.2.11/analogRead?pin=A0')
    print(r.json())
    

#PWM sensor
def pwm():
    r = requests.get('http://192.168.2.11/analogWrite?pin=4&value=10')
    time.sleep(2)
    r = requests.get('http://192.168.2.11/analogWrite?pin=4&value=100')
    time.sleep(2)
    r = requests.get('http://192.168.2.11/analogWrite?pin=4&value=200')
    time.sleep(2)
    r = requests.get('http://192.168.2.11/analogWrite?pin=4&value=0')
    print(r.json())
   

#serial communication
def serialcommunication():
    r = requests.get('http://192.168.2.11/serialBegin?baud=2')
    time.sleep(2)
    print(r.json())
    r = requests.get('http://192.168.2.11/serialWrite?data=Hello')
    time.sleep(2)
    print(r.json())
    r = requests.get('http://192.168.2.11/serialRead')
    time.sleep(2)
    print(r.json())
main()
