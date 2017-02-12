import os
from setuptools import setup, Extension

setup(
        name='spam',
        version='0.0.1',
        classifiers=['Silly status'],
        ext_modules=[
            Extension('spam',
                ['spam.cpp'],
                libraries=['boost_python', 'python2.7'],
                )
            ],
        )
