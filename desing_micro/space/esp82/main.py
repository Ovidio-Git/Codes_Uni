from machine import Pin
from time import sleep


def current(n):
	pin = machine.Pin(2, machine.Pin.OUT)
	adc = machine.ADC(0)
	print(adc.read())


def run():
	current()


if __name__ == '__main__':
	run()
