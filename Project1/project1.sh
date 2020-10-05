#!/bin/bash

# file project1.sh
# brief 1st script, to hopefully create a webpage filled with sys info
# author rory.beebout
# assignment Project - Scripting 1
# date 10/5/2020

#functions

# brief Writes Basic HTML for webpage, from linuxcommand.org "Here Scripts"
cat <<- _EOF_
    <html>
    <head>
        <title>
        $HOSTNAME System Information
        </title>
    </head>

    <body>
    <h1>HOSTNAME: $HOSTNAME</h1>
    </body>
    </html>
_EOF_#!/bin/bash
