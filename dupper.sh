#!/bin/bash
# uppercase COM and EXE files for the DOS
# Project Crew™ 10/2/2026
find -maxdepth 1 -iname '*.com' -print0 -o -iname '*.exe' -print0 |
  xargs -0 rename -v 'y/a-z/A-Z/'
