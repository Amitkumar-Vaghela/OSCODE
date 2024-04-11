import os
import multiprocessing

def child_process():
    print("I am child process.")
    print("ID:", os.getpid())

def main():
    print("Name: Amitkumar vaghela , ERP: 2203031050777")
    
    # Create a new process
    p = multiprocessing.Process(target=child_process)
    p.start()
    p.join()  # Wait for the child process to finish

    print("I am parent process:")
    print("ID:", os.getpid())

if __name__ == "__main__":
    main()

