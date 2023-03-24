import requests
import random
import string
import colorama
import time
from colorama import Fore
import argparse

parser = argparse.ArgumentParser(description='Generate a random username.')
parser.add_argument('-l', '--length', type=int, default=4, help='size length of the username')
parser.add_argument('-u', '-U', type=str, help='Checks for a given username')
args = parser.parse_args()
Checked_Usernames = []
check1 = "Couldn't find any profile with that name"
check_once = False
def get_random_string(length):
    # choose from all lowercase letter
    letters = string.ascii_lowercase + string.digits + "_"
    result_str = ''.join(random.choice(letters) for i in range(length))
    Checked_Usernames.append(Checked_Usernames)
    return result_str

while True:
    try:
        if args.u:
            username = args.u
            check_once = True
        else:
            username = str(get_random_string(args.length)) #Replace the number inside here for how many characters long you want the username
        if username not in Checked_Usernames:
            url = f'https://api.mojang.com/users/profiles/minecraft/{username}?'
            response = requests.get(url)
            if response.status_code == 204 or response.status_code == 404:
                print(Fore.GREEN, "Username available: ", username) # Needs more checks
                if check_once:
                    break
            elif response.status_code == 200:
                uuid = response.json()['id']
                print(Fore.RED, "Username unavailable: ", username)
                if check_once:
                    break
            else:
                print(Fore.MAGENTA, "Being Rate Limited Waiting.", end="\r", flush=True)
                time.sleep(1)
                print(Fore.MAGENTA, "Being Rate Limited Waiting..", end="\r", flush=True)
                time.sleep(1)
                print(Fore.MAGENTA, "Being Rate Limited Waiting...")
        else:
            pass

    except KeyError:
        pass
