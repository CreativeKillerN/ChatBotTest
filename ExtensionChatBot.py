# chatbot_extension.py
import subprocess

def main():
    cpp_program = subprocess.Popen(["./chatbot"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)

    print("Python: Hello! Ask me a question or say 'bye' to exit.")
    while True:
        question = input("You: ")

        if question == "bye":
            print("Python: Goodbye! Have a great day.")
            break

        cpp_program.stdin.write(question + '\n')
        cpp_program.stdin.flush()

        answer = cpp_program.stdout.readline().strip()
        print("ChatBot++:", answer)

    cpp_program.stdin.close()
    cpp_program.stdout.close()

if __name__ == "__main__":
    main()
