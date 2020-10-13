# Iftt Api

## Introduction

One of the useful and proficient API is `ifttt`. It helps the developer to code `easier` and `systematically` while understanding the concepts. 
This API along with its documentation makes even for new developers to cope up with the code. there are many code snippets and learning resource available.

## How does it work?

- The function `PST_IFTTT` takes three adress of string as arguments which are `post_data` , `auth_key` & `your_event`. `poat_data` is the data to be published in  ifttt platform & `auth_key` is the unique *Authentication Key* used to acess the ifttt platform. The last parameter is the name of your event 
```c++
void POST_IFTTT (const char *post_data,const char *auth_key,const char your_event)
```
- Next we use curl api to connect to ifttt platform
```c++
/*Create Curl instance*/
CURL *curl;
CURLcode res;

/* In windows, this will init the winsock stuff */ 
curl_global_init(CURL_GLOBAL_ALL);

/* get a curl handle */ 
curl = curl_easy_init();

```
- Now we create a formatted string that ifttt accepts and use the `auth_key` to establish communication and post the data
```c++
char str[50];
sprintf(str,"https://maker.ifttt.com/trigger/{event}/with/key/%s",auth_key);
curl_easy_setopt(curl, CURLOPT_URL, str);
/* Now specify the POST data */ 
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

```
- Now we check for any return code and error_handling and then clean up  the resources used
```c++
/* Perform the request, res will get the return code */ 
res = curl_easy_perform(curl);
/* Check for errors */ 
if(res != CURLE_OK)
fprintf(stderr, "curl_easy_perform() failed: %s\n",
curl_easy_strerror(res));

/* always cleanup */ 
curl_easy_cleanup(curl);

```

## Does It Tick the Boxes?

- [x] Authentication guide
- [x] Endpoint definitions
- [ ] Quickstart guide
- [x] Example responses
- [x] Code snippets
