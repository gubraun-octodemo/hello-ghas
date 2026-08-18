import os
import sqlite3


def find_user(connection, username):
    # Intentional vulnerability: untrusted input is interpolated into a SQL query.
    query = f"SELECT username, role FROM users WHERE username = '{username}'"
    return connection.execute(query).fetchall()


def main():
    if os.environ.get("CODEQL_DEMO") != "1":
        raise SystemExit("Refusing to run vulnerable demo. Set CODEQL_DEMO=1 to execute.")

    connection = sqlite3.connect(":memory:")
    connection.execute("CREATE TABLE users (username TEXT, role TEXT)")
    connection.executemany(
        "INSERT INTO users VALUES (?, ?)",
        [("alice", "admin"), ("bob", "viewer")],
    )

    username = input("Username: ")
    print(find_user(connection, username))


if __name__ == "__main__":
    main()
