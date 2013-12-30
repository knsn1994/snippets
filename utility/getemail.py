def getEmail(s):
    return s.replace(' ','').replace('(dot)','.').replace('(at)','@').replace('[dot]','.').replace('[at]','@')
    
print getEmail(raw_input(    ))