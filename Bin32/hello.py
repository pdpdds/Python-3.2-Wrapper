def simple():
    print("I am so simple !")

def multiply(a,b):
    "Multipies the other way round!"
    c = 0
    for i in range(0, a):
        c = c + b
    return c

def echo(s):
    "talk back!"
    return s

def names_as_list():
    return ['Sam', 'Annie', 'Jake'];

def names_as_tuple():
    return ('Sam', 'Annie', 'Jake');

def config():
    return {"user" : "joe", "id" : 345, "password" : "XcjjdJJ",
            "email" : ("joe@someserver.com", "joe@someotherserver.com") }
