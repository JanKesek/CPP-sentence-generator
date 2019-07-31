egrep -o "^[0-9]{8}\s[0-9]{2}\s[a-z]\s[0-9]{2}\s[a-zA-Z]*\s" ./dict/data.adv | cut -d ' ' -f 5 > conv.data.adv
egrep -o "^[0-9]{8}\s[0-9]{2}\s[a-z]\s[0-9]{2}\s[a-zA-Z]*\s" ./dict/data.adj | cut -d ' ' -f 5 > conv.data.adj
egrep -o "^[0-9]{8}\s[0-9]{2}\s[a-z]\s[0-9]{2}\s[a-zA-Z]*\s" ./dict/data.verb | cut -d ' ' -f 5 > conv.data.verb
egrep -o "^[0-9]{8}\s[0-9]{2}\s[a-z]\s[0-9]{2}\s[a-zA-Z]*\s" ./dict/data.noun | cut -d ' ' -f 5 > conv.data.noun
sed -i -e 's/^/<noun> /' conv.data.noun 
sed -i -e 's/^/<verb> /' conv.data.verb 
sed -i -e 's/^/<adj> /' conv.data.adj
sed -i -e 's/^/<adv> /' conv.data.adv 


