def load_activities():
    try:
        with open("./python/data/activities.txt", "r") as log_file:
            return log_file.readlines()
    except FileNotFoundError:
        return []


def add_activity(activities, activity):
    for act in activities:
        if act.strip() == activity:
            print("Activity already exists.")
            return activities

    activities.append(activity + "\n")

    write_activities(activities)

    return activities


def write_activities(activities):
    with open("./python/data/activities.txt", "w") as log_file:
        for activity in activities:
            log_file.write(activity)


def print_activities(activities):
    print("Your activities:")
    for idx, act in enumerate(activities, start=1):
        print(f"{idx}. {act.strip()}")


while True:
    activity = input("Enter your activity: ")

    if activity.lower() == "exit":
        print("Exiting activity tracker.")
        break

    activities = load_activities()

    activities = add_activity(activities, activity)

    print_activities(activities)
