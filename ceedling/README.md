# Ceedling

Tool to test the project source code.

## Prerequisites

Before using Ceedling, make sure you have the following items installed on your system:

1. **Ruby**: Required to manage Ceedling, the testing framework.
2. **Ceedling**: A tool that integrates Unity (for unit tests), CMock (for mocks), and CException (for exception handling).

### Installing Ruby (Linux)
Run the following command to install Ruby on your system:
```bash
sudo apt install ruby
```

### Installing Ruby (Windows)
Run the following command to install Ruby using Chocolatey:
```bash
choco install ruby
```

### Installing Ruby (macOS)
Run the following command to install Ruby using Homebrew:
```bash
brew install ruby
```

### Installing Ceedling
After installing Ruby, install Ceedling with the command:
```bash
gem install ceedling
```

### Running All Tests
To run all test cases, execute:
```bash
ceedling
```

### Running Specific Tests
To run tests for a specific module:
```bash
ceedling test:<module>
```
Replace `<module>` with the name of the module.

### Cleaning Build Files
To clean the compiled files and reset the environment:
```bash
ceedling clean
```
