

from flask import Flask


app = Flask(__name__)


@app.route('/')
def index():
	return "Hola mundo,llegamos a la web papa!"

if __name__ == '__main__':
	app.run()
