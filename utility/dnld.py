#!/usr/bin/env python
# This script is written for downloading files from a very specific page.
# In this code, the source html is assumed to be stored already, however, isntead, it can be obtained urllib2 itself.
# In this script only certain pdf files are downloaded which are filtered using a regex. Modify the regex (line 10) appropriately.
import urllib2
import re
source = open('src.html', 'r')
text = source.read()
source.close()
lis = re.findall('(http://spar.*?pdf)', text)
print "Total", len(lis), "files are there"
cnt = 0
for x in lis:
    print "Downloading file #", cnt
    f = open(str(cnt)+'.pdf', 'w')
    f.write(urllib2.urlopen(x).read())
    f.close()
    print "File #", cnt, "downloaded"
    cnt += 1
print "Completed"
