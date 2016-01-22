#!/cygdrive/c/Python34/python.exe
#=============================================================================
#
# Accessing the Win32 API using ctypes in Python
#
#=============================================================================

"""
Accessing the Win32 API using ctypes in Python
==============================================
"""


import ctypes
import sys


__version__ = '0.0.0'


#=============================================================================
def hello():
    """
    Hello world with ctypes binding to Win32 API.

    MessageBoxW(
        NULL,
        L"Hello World!",
        L"Greetings",
        ( MB_OK | MB_ICONINFORMATION )
    );

    """

    # Constants that are normally available in the Windows headers
    MB_OK              = 0x00000000
    MB_ICONINFORMATION = 0x00000040
    IDOK               = 1

    # Call the function using the `windll` binding.
    result = ctypes.windll.User32.MessageBoxW(
        None,
        'Hello World!',
        'Greetings',
        ( MB_OK | MB_ICONINFORMATION )
    )

    # Example of checking the return value.
    if result != IDOK:
        print( 'OK button was not clicked!' )


#=============================================================================
def main( argv ):
    """
    Script execution entry point

    @param argv List of arguments passed to the script
    @return     Shell exit code (0 = success)
    """

    # imports when using this as a script
    import argparse

    # create and configure an argument parser
    parser = argparse.ArgumentParser(
        description = 'Accessing the Win32 API using ctypes in Python.',
        add_help    = False
    )
    parser.add_argument(
        '-h',
        '--help',
        default = False,
        help    = 'Display this help message and exit.',
        action  = 'help'
    )
    parser.add_argument(
        '-v',
        '--version',
        default = False,
        help    = 'Display script version and exit.',
        action  = 'version',
        version = __version__
    )

    # parse the arguments
    args = parser.parse_args( argv[ 1 : ] )

    # run the example
    hello()

    # return success
    return 0


#=============================================================================
if __name__ == "__main__":
    sys.exit( main( sys.argv ) )

