import base64
import os

TICKET_SIZE = 0x1000


class SteamId:
    steamId3: int

    def __init__(self, steamId3: int):
        self.steamId3 = steamId3

    def get_account_id(self):
        return self.steamId3 & 0x00000000ffffffff


class Ticket:
    base64: str

    def __init__(self, base64: str):
        self.base64 = base64

    def get_bytes(self):
        return base64.b64decode(self.base64)

    def get_size(self):
        return len(self.get_bytes())


def main() -> int:
    steam_id: SteamId
    ticket: Ticket

    with open("./configs.user.ini", "r") as f:
        for line in f.readlines():
            if "=" not in line:
                continue

            split = line.split("=")
            if split[0] == "account_steamid":
                steam_id = SteamId(int(split[1].strip()))
            elif split[0] == "ticket":
                ticket = Ticket(split[1].strip())

    print("SteamId: " + str(steam_id.get_account_id()))
    print("Bytes: " + str(ticket.get_bytes()))
    print("Size: " + str(ticket.get_size()))

    with open("encryptedTicket_", "wb") as f:
        size = ticket.get_size()

        # Cheap way to reverse the bytes
        f.write(steam_id.get_account_id().to_bytes(4)[::-1])
        f.write(size.to_bytes(4)[::-1])
        f.write(ticket.get_bytes())
        f.write(bytes(TICKET_SIZE - size))
        f.flush()

    return 0


main()
