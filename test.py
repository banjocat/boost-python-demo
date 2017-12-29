import spam
import time

def timeme(method):
    def wrapper(*args, **kw):
        startTime = int(round(time.time() * 1000))
        result = method(*args, **kw)
        endTime = int(round(time.time() * 1000))

        print(endTime - startTime,'ms')
        return result

    return wrapper

spam.greet('cassie')

spam.system('ls')

print spam.strlen("1234")

def python_fb(num):
    result = []
    first = 0
    second = 1
    for i in xrange(num):
        if i <= 1:
            next = i
        else:
            next = first + second
            first = second
            second = next
        result.append(next)
    return result

@timeme
def cppfib():
    [x for x in spam.fibonacci(100000)]

@timeme
def pyfib():
    [x for x in python_fb(100000)]

@timeme
def boost_dict():
    spam.create_a_dict()

@timeme
def python_dict():
    for i in xrange(1,10000000):
        _python_dict()

def _python_dict():
    x = {}
    x["message"] = "Hello World"
    l = []
    l.append('This')
    l.append('is')
    l.append('a')
    l.append('list')
    x['list'] = l;

boost_dict()
python_dict()

