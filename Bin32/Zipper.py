#------------------------------------------------------------------------------
#           Name: write_files_to_zip.py
#         Author: Kevin Harris
#  Last Modified: 02/13/04
#    Description: This Python script demonstrates how to use zipfile to write
#                 some files into a zip archive.
#------------------------------------------------------------------------------

import os
import zipfile

def Pack(filename, extention) :
# List all files in the current directory
    allFileNames = os.listdir( os.curdir )

# Open the zip file for writing, and write some files to it
    myZipFile = zipfile.ZipFile( filename, "w" )

# Write each file present into the new zip archive, except the python script
    for fileName in allFileNames:
        (name, ext) = os.path.splitext( fileName )
        if ext == "." + extention:
            print ("Writing... " + fileName)
            myZipFile.write( fileName, os.path.basename(fileName), zipfile.ZIP_DEFLATED )

    myZipFile.close()
