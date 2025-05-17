#!/usr/bin/env python3

import sys

# Read user input from command line arg

if len(sys.argv) < 2:
    print("ERROR: No input received", file=sys.stderr)
    sys.exit(1)

user_input = sys.argv[1]

# Simulated response as a placeholder or GPT

response = f"[GPT-DM] I received your input: {user_input}"
print(response)
