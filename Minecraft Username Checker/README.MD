
# A Simple Minecraft Username Checker

A simple minecraft username checker which checks the username using mojang's API.
<br>
Can also be used to randomly check for usernames with a given length.


## How To Use

There are three methods of running the file.

The first one is shown below, this takes no extra arguments:

```bash
python isavailable.py
```

The second shown below takes an extra argument of `-l` or `--length`, followed by an integer as input

```bash
  python isavailable.py -l 3
```

Lastly the final one shown below takes an extra argument of  `-u` or `-U`, followed by an string as input

```bash
  python isavailable.py -u example
```

<br>

Sometimes the below might appears (It waits for a few seconds):

```diff
@@ Being Rate Limited . . .@@
```
<br>
This happens when we hit the rate limit of 200 requests per minute.
<br>

## Dependencies

To install required dependencies just run the command below (Using `pip`):

```bash
pip install -r requirements.txt
```
    