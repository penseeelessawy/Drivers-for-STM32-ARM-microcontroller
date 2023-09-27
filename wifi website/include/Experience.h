 static const char ECHO[]        = "ATE0\r\n";
 static const char TEST[]        = "AT\r\n";
 static const char CONFIG[]="AT+CWMODE_CUR=1\r\n";

		 static const char CONNECT_WIFI[]=		 "AT+CWJAP_CUR = \"OMAR\",\"001550084051\"\r\n" ;
		 static const char CONNECT_SITE[]=	 "AT+CIPSTART=\"TCP\",\"pensee.freevar.com\",80\r\n";

		 static const char SEND[]=	 "AT+CIPSENDT=43 bytes";
		 static const char GET[]=	 "GET http://pensee.freevar.com/status.txt";
