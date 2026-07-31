import subprocess


def run_ping(host):
    # Intentional vulnerability: command injection via shell=True with untrusted input.
    return subprocess.check_output(f"ping -c 1 {host}", shell=True, text=True)


def print_name_length(user):
    # Intentional quality issue: possible None dereference.
    print(len(user.name))


if __name__ == "__main__":
    import os
    if os.environ.get("CODEQL_DEMO") != "1":
        raise SystemExit("Refusing to run vulnerable demo. Set CODEQL_DEMO=1 to execute.")

    user_input = input("Host to ping: ")
    print(run_ping(user_input))

    try:
        print_name_length(None)
    except Exception as exc:
        print(f"Expected demo failure: {exc}")
