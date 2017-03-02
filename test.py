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
def fib():
    [x for x in spam.fibonacci(100000)]

@timeme
def pyfib():
    [x for x in python_fb(100000)]



fib()
pyfib()

