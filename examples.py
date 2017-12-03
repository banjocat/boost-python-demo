import spam


# Create a dict from C++ with a list
d = spam.create_a_dict()
print(d['message'])
print(type(d['list']))
print(d['list'])


# Convert value of dict in C++
p = {
    'language': 'Python'
}
print(p['language'])
spam.change_a_dict(p)
print(p['language'])



