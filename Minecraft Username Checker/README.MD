
# A Simple Minecraft Username Checker

A simple minecraft username checker which checks the username using mojang's API.


## How To Use

There are two methods of running the file.

The first one is shown below, this takes no extra arguments:

```bash
  python isavailable.py
```

![No Arguments](https://gyazo.com/64b333f6eca800ad6eb382075f177d6b.gif)

<br><br>
The second shown below takes an extra argument `-l` or `--length`, followed by an integer

```bash
  python isavailable.py -l 3
```

![with length](https://gyazo.com/e3e1d5adfcb0e56ca036429dd4aac761.gif)
<br>
Sometimes the below might appears (It waits for a few seconds):
<br>
![When being rate limited](https://gyazo.com/289928ca0d7bdd25921c7ba733079d38.png)

This happens when we hit the rate limit of 200 requests per minute.
<br>
## Dependencies

To install required dependencies just run the command below (Using `pip`):

```bash
pip install -r requirements.txt
```
    