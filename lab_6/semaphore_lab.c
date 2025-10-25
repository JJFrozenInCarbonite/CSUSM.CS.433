# midterm.py  -- TI-84 Plus CE Python friendly

def estimating_total_cpu_time():
    print("S(n+1) = a*T(n) + (1-a)*S(n)")
    try:
        a = float(input("a: "))
        tn = float(input("T(n): "))
        sn = float(input("S(n): "))
    except:
        print("Invalid number. Try again.")
        return
    sn1 = a * tn + (1.0 - a) * sn
    print("S(n+1):", sn1)

def interactive_process_scheduling():
    # Q = (M - P*S) / (P - 1)
    # S% = S / (Q + S) * 100
    try:
        p = float(input("Number of processes (P): "))
        s = float(input("Context switching time (S): "))
        m = float(input("Time limit (M): "))
    except:
        print("Invalid number. Try again.")
        return
    if p <= 1.0:
        print("Error: P must be > 1")
        return
    q = (m - (p * s)) / (p - 1.0)
    denom = q + s
    if denom == 0.0:
        print("Error: Q + S is zero; cannot compute S%")
        return
    perc = (s / denom) * 100.0
    print("Q formula: (M - (P * S)) / (P - 1)")
    print("Q:", q)
    print("S% formula: S / (Q + S) * 100")
    try:
        print("S%: " + "{:.2f}".format(perc))
    except:
        print("S%:", perc)

def main():
    print("Midterm Calculator")
    print("1: Estimate Total CPU Time")
    print("2: Interactive Process Scheduling")
    print("X: Exit")
    choice = input("Choose an option: ").strip()
    if choice == "1":
        estimating_total_cpu_time()
    elif choice == "2":
        interactive_process_scheduling()
    elif choice.upper() == "X":
        print("Goodbye!")
    else:
        print("Invalid choice. Exiting...")

# Call main() directly so the menu always prints on run
main()
