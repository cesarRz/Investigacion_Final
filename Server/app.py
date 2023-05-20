from flask import Flask, request, render_template, redirect, url_for
import socket
import csv
import os

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


def send_csv_data(data):
    path  = os.path.join(app.root_path,"..","coordenadas.csv")
    
    with open(path, 'w') as f:
    # Create a CSV writer object
        writer = csv.writer(f)
        # Write the data to the CSV file
        writer.writerow(data)

@app.route('/')
def hello():
    return redirect(url_for('controller'))


@app.route('/giroscopio/', methods=['GET', 'POST'])
def giroscopio():

    x = request.form.get('x')
    y = request.form.get('y')
    print(x, y)
    if x != None:
        data = [x,y]
        send_csv_data(data)

    return render_template("giroscopio.html")

@app.route('/send-data/', methods=['GET'])
@app.route('/send-data/<direccion>', methods=['POST', 'GET'])
def send_data(direccion=''):
    if direccion != "":
        response = send_data_to_socket(direccion, "localhost", 5002)
        print(response)
    return render_template("botones.html")

@app.route('/controller/', methods=['GET'])
@app.route('/controller/<direccion>', methods=['POST', 'GET'])
def controller(direccion=''):
    if direccion != "":
        response = send_data_to_socket(direccion, "localhost", 5002)
        print(response)
    return render_template("control.html")


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')