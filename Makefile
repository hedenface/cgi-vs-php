NUMREQS=100
CONCURRENTREQS=10
TESTCOUNT=166

compile:
	gcc -O0 -o test-opt0.cgi test.c
	gcc -O1 -o test-opt1.cgi test.c
	gcc -O2 -o test-opt2.cgi test.c
	gcc -O3 -o test-opt3.cgi test.c

install:
	sudo cp test.php /var/www/html/
	sudo cp test-opt*.cgi /usr/lib/cgi-bin/

test:
	@echo "***********************"
	@echo "test.php"
	@echo "***********************"
	ab -n $(NUMREQS) -c $(CONCURRENTREQS) "http://localhost/test.php?print&count=$(TESTCOUNT)"

	@echo "***********************"
	@echo "test-opt0.cgi (no optimization [-O0])"
	@echo "***********************"
	ab -n $(NUMREQS) -c $(CONCURRENTREQS) "http://localhost/cgi-bin/test-opt0.cgi?print&count=$(TESTCOUNT)"

	@echo "***********************"
	@echo "test-opt1.cgi (-O1 optimization)"
	@echo "***********************"
	ab -n $(NUMREQS) -c $(CONCURRENTREQS) "http://localhost/cgi-bin/test-opt1.cgi?print&count=$(TESTCOUNT)"

	@echo "***********************"
	@echo "test-opt2.cgi (-O2 optimization)"
	@echo "***********************"
	ab -n $(NUMREQS) -c $(CONCURRENTREQS) "http://localhost/cgi-bin/test-opt2.cgi?print&count=$(TESTCOUNT)"

	@echo "***********************"
	@echo "test-opt3.cgi (-O3 optimization)"
	@echo "***********************"
	ab -n $(NUMREQS) -c $(CONCURRENTREQS) "http://localhost/cgi-bin/test-opt3.cgi?print&count=$(TESTCOUNT)"
