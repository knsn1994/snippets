tell application "Google Chrome"
	open location "https://proxy22.iitd.ernet.in/cgi-bin/proxy.cgi"
	tell active tab of window 1
		repeat while loading is true
			delay 0.1
		end repeat
		execute javascript "document.getElementsByName('userid')[0].value('<username>');"
		execute javascript "document.getElementsByName('pass')[0].click('<pass>');"
		execute javascript "document.getElementsByName('logon')[0].click();"
	end tell
end tell
