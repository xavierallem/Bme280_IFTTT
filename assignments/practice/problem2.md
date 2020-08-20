# Problem 2

### Purpose : Demo for n8n platform

Write code which monitors these parameters 
1. temperature using BME280 sensor
2. CPU RAM usage of the docker.

And sends the webhook to n8n platform when
1. Temperature using BME280 reaches higher than 30 deg C
2. CPU RAM usage of the docker reaches higher than 100 MB  

n8n then sends you an email that the Temperature is high or the RAM usage is high.

#### Outcomes 
1. C/CPP `iftt_demo.cxx` code which contains functions that can be used to send data to the n8n platform.
1. Tutorial Document on n8n demo.
1. Guide Document on using n8n functions to send webhooks to n8n platform.


### Steps to complete

1. Use the codes from module 4 to write demo for the n8n platform. 
1. Install n8n on your machine - https://docs.n8n.io/getting-started/quickstart.html#quickstart
1. Create an n8n webhook service - [link](https://thepihut.com/blogs/raspberry-pi-tutorials/using-ifttt-with-the-raspberry-pi) 
1. Test the codes using the [Shunya OS docker](https://gitlab.iotiot.in/snippets/52) container.

**Note** : While testing the BME280 will not work on the docker hence, please test it with the CPU RAM usage only.

### Acceptance Criteria 
This is the criteria to accept the assignment.
- **Must** follow the Coding Standards.
- The code **Must** use the cURL library.
