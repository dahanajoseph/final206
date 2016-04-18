#!/usr/bin/python
import sys
import os
import cgitb
import cgi

cgitb.enable()

# 1. Read users.txt and takes each users (except himself) and displays them with a check button
#   a) open the file
#   b) look for the username : if it is the current user, next
#   c) prints the username
#   d) go to the full name and prints it (breakpoint)
#   e) c and d are done will printing the html file makefriends.html




print "Content-Type:text/html\n\n"
print

arguments = cgi.FieldStorage()
currentuser = arguments.getvalue("ID")

def Catalog():
    
    



# open the makefriends.html file

    try:
        htmlfile = open("dashboard.html", "r")
    
    except IOError:
        print "Please tell it to your litterate grandmas. Code : IOError - makefriends.py - open dashboard.html"
        sys.exit()

# prints the beggining of the html file, untilbreakpoint
#...

    html = htmlfile.readlines()

    for line in html:

        breakpoint = line.rstrip('\n')
        if breakpoint=="HIDDEN":
	    breakline = '<input type="hidden" name="ID" value="' + currentuser + '">'
            print breakline

	elif breakpoint=='value="USERNAME">':
	    breakline = 'value="' + currentuser + '">'
	    print breakline

	elif breakpoint != "CHECKBOXES":
	    print breakpoint


#------------------------------------------------------------------------------------------------------
# prints the checkboxes


# first line of the file

		
		print '<h1 id="friends"> Withdraw <form type="radio" name="transaction" value="w"><br/>'
                print '<h1 id="friends"> Depose <form type="radio" name="transaction" value="d"><br/>'
                print '<h1 id="friends"> Transfer <form type="radio" name="transaction" value="w"><br/>'
                print '<h1 id="friends"> See balance <form type="radio" name="transaction" value="b"><br/>'
            


    htmlfile.close()



# end of catalog




Catalog()
