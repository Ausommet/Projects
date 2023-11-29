
#  Link Hunter By Group-17

  Link Hunter, a powerful online tool to observe information spreading (i.e Links) on Reddit.

  Key Technologies:
 - Python: The core programming language driving Link Hunter's
   functionality.
 - SQLAlchemy: Empowering the tool with a versatile and efficient SQL   
   toolkit for database management.
 - Flask: Serving as the web framework, Flask enables a seamless and   
   responsive user interface.
 - PRAW (Python Reddit API Wrapper): Leveraging PRAW to interact with   
   Reddit's API, ensuring accurate and up-to-date information retrieval.

  

##  Contributors

  

* Iustinian - Lead Developer, Project Manager, Team Leader, Tester, Project Coordinator and Technical Writer

  

* Ben - Programmer, Assistant Project Manager, Designer

  

* Jake - Programmer

  

* Ash - Programmer

  

* Stuart - Programmer

  

* Jac - Programmer, Designer

  

* Konstantinos - Programmer, Designer

  

* Rudresh - Programmer, Designer

  

  

#  Installing Required Dependencies

  

**To install Depenencies**

  

> `pip install -r requirements.txt`

  

#  Running the project through LocalHost

To run the project your terminal/CLI must be opened inside the same folder as the project.

<br/>

***Be sure that you've installed the required dependencies before trying this stage!***

  

|Operating System|Commands  |
|--|--|
|**Windows 10 & 11**  |python app.py **or** python3 app.py  |
|**Linux**  |python3 app.py  |
| **MacOS** | python3 app.py |

  

#  Setting Up Database

  
To setup the database, it can be done by changing the following below:

  

    db = "mysql+pymysql://USERNAME:PASSWORD@HOST/DATABASE?charset=utf8mb4"
    
    engine = create_engine(
    
    db, connect_args={
    
    "ssl": {
    
    "ssl_ca": "/etc/ssl/cert.pem"
    
    }}

*Sometimes the client when changing the database may run into some issues with the **SSL permits**. Due to some Database hosts requiring **different** verifications for SSL, therefore I'm unable to provide example/help for the issue itself. **However the host may be able to provide guidance on how to configure SSL settings properly or provide alternative solutions for establishing a secure connection to the database.***

  

##  Prerequisits required for the Database

####  Creating the Table

  

    CREATE TABLE `main` (
    
    `id` int NOT NULL AUTO_INCREMENT,
    
    `link` varchar(500) DEFAULT NULL,
    
    `created_at` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
    
    `jdata` json DEFAULT NULL,
    
    PRIMARY KEY (`id`)

  

This is all that is required to implement their own Database, since almost everything is controlled through the database_query.py and a call is used inside app.py for the downloading of the raw_data.json.

  

Inside database.py update it to your own database along side the required Keys to access the Database, as shown below:

Change the following below to your own database/server.

    HOST=HOSTNAME
    
    USERNAME=USERNAME
    
    PASSWORD=PASSWORD
    
    DATABASE=DATABASENAME

#  Setting up Reddit API
 Inside API.py, all that is needed is to add your own client_id, client_secret, user_agent, username and password
 

     reddit = praw.Reddit(client_id ='CLIENTID',
    
    client_secret ='CLIENTSECRET',
    
    user_agent ='USERAGENT',
    
    username="USERNAME", password = "PASSWORD	")

#  Hosting the Website

For the demonstration, we have setup a simple hosting for the group project hosted on the web.

And it can be accessed by following the link below *(Update: Now Disabled)*.

> https://group17demo.onrender.com

  

Keeping in mind that since we are using the **Free** version, the same goes for the database. The server may sometimes take a moment for it to load since it may require a re-boot of the server hosting it.

###  Demo of setting up a host for the website on render.com

  

![Stage 1](IFRM/1.png?raw=true)

![Stage 2](IFRM/2.png?raw=true)

![Stage 3](IFRM/3.png?raw=true)

![Stage 4](IFRM/4.png?raw=true)

![Stage 5](IFRM/5.png?raw=true)

![Stage 6](IFRM/6.png?raw=true)

![Stage 7](IFRM/7.png?raw=true)

![Stage 8](IFRM/8.png?raw=true)

![Stage 9](IFRM/9.png?raw=true)

![Stage 10](IFRM/10.png?raw=true)
