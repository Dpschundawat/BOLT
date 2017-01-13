#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>


int Ledon()
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/digitalWrite?pin=1&state=HIGH&deviceName=BOLT14095506");

    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  return 0;
}

int Analog_sensor()
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/analogRead?pin=A0&deviceName=BOLT14095506");
	res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
		curl_easy_cleanup(curl);
  }
  return 0;
}

int Digital_sensor()
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/digitalRead?pin=4&deviceName=BOLT14095506");
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res)); 
    curl_easy_cleanup(curl);
  }
  return 0;
}

int PWM()
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/analogWrite?pin=3&value=10&deviceName=BOLT14095506");
    res = curl_easy_perform(curl);
    sleep(5);
    fflush(stdout);
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/analogWrite?pin=3&value=100&deviceName=BOLT14095506");
    res = curl_easy_perform(curl);
    sleep(5);
    fflush(stdout);
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/analogWrite?pin=3&value=200&deviceName=BOLT14095506");
    res = curl_easy_perform(curl);
    sleep(5);
    fflush(stdout);
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/analogWrite?pin=3&value=0&deviceName=BOLT14095506"); 
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  return 0;
}

int Ledoff()
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://139.59.25.153/remote/e88549e0-6fdb-45a3-9a7b-5e8149bb2323/digitalWrite?pin=1&state=LOW&deviceName=BOLT14095506");
	res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  return 0;
}


int main()
{
  int l;
  int n;
  puts("\n testing of bolt");

  while(1)
  {
    puts("\n Choose an option");
    puts("\n 1. Ledon");
    puts("\n 2. Analog_sensor");
    puts("\n 3. Digital_sensor");
    puts("\n 4. PWM");
    puts("\n 5. Ledoff");

    scanf("%d", &l);

    switch(l)
    {
      case 1:
      {

        Ledon();
        break;
      }

      case 2:
      {
        Analog_sensor();
        break;
      }

      case 3:
      {
        Digital_sensor();
        break;
      }

      case 4:
      {
        PWM();
        break;
      }

      case 5:
      {
        Ledoff();
        break;
      }

      default:
      {
        printf("Wrong choice");
        return 0;
      }
    }
  }
}