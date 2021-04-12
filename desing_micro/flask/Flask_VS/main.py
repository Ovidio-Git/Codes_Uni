from flask import Flask, request, make_response,redirect, render_template, session


app = Flask(__name__)


app.config['SECRET_KEY'] = 'clave impenetrable' 


todos = ['you want buy?', 'you want sell?', 'you want exit?']
#para que el template pueda utilizar esta lista necesitamos pasarla
#como parametro a render_template



@app.errorhandler(500)
def server_error(error500):
    return render_template('500.html', error500=error500)

@app.errorhandler(404)
def not_found(error):
    return render_template('404.html', error=error)



@app.route('/')
def index():
    user_ip = request.remote_addr

    response = make_response(redirect('/sms'))
    response.set_cookie('user_ip',user_ip) # Poner una cookie que se llamara user ip
    session['user_ip'] = user_ip
    return response


@app.route('/sms')
def sms():
    # para que la funcion sms obtenga el user ip directamente desde las cokies del browser 
    user_ip = request.cookies.get('user_ip')
    user_ip = session.get('user_ip  ')
    context = {
        'user_ip':user_ip,
        'todos': todos,
 
    }
    return render_template('sms.html', **context)


    
if __name__ == '__main__':
	app.run()
