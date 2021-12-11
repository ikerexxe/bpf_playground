#!/bin/bash

/usr/share/bcc/tools/trace 'pam:pam_start "%s: %s", arg1, arg2'
