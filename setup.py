#!/bin/env python2

from subprocess import call

import setuptools.command.build_py
from setuptools import setup, find_packages

class BuildPyCommand(setuptools.command.build_py.build_py):
  """Custom build command."""

  def run(self):
    call(["pip", "install", "-r", "requirements.txt"])
    call(["./download-crypto-sdk.sh"])
    call(["./build.sh"])

    setuptools.command.build_py.build_py.run(self)


setup(
    cmdclass={
        'build_py': BuildPyCommand,
    },
    packages=find_packages('src'),  # include all packages under src
    package_dir={'':'src'},   # tell distutils packages are under src
    include_package_data=True,    # include everything in source control
    name = 'orbs-client-sdk',
    version = '0.1.0',
    description = 'Orbs Client SDK',
    author = 'Kirill Maksimov',
    author_email = 'kirill@orbs.com',
    url = 'https://github.com/orbs-network/orbs-client-sdk-python'
)
