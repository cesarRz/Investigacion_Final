from flask import Flask, request, render_template, redirect, url_for
import socket

app = Flask(__name__)


import socket

def send_data_to_socket(data, host, port):
    # Create a socket object
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # Connect to the server
    s.connect((host, port))
    # Send the data to the server
    s.sendall(data.encode())
    # Receive the response from the server
    response = s.recv(1024)
    # Close the socket
    s.close()
    # Return the response from the server
    return response.decode()


@app.route('/')
def hello():
    return 'Hello, World!'


@app.route('/giroscopio/')
def giroscopio():
    return render_template("giroscopio.html")

@app.route('/send-data/', methods=['GET'])
@app.route('/send-data/<direccion>', methods=['POST', 'GET'])
def send_data(direccion=''):

    if direccion != "":
        response = send_data_to_socket(direccion, "localhost", 5002)
        print(response)
        

    return render_template("botones.html")


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')