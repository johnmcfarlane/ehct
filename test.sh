PROJECT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ "$PROJECT_DIR" = "$PWD" ]; then
  echo "Error: This script erases the working directory. You probably do not want to run it from here."
  exit 1
else
  read -p "Warning: working directory is about to be erase! Press <enter> if you are sure or CTRL-C to quit.
"
fi

echo --------
echo Compiler:
c++ --version

rm -rf *
cmake $PROJECT_DIR -DCMAKE_BUILD_TYPE=Release > /dev/null
cmake --build . > /dev/null

echo --------
echo With Exceptions and RTTI Enabled
du enabled -b
time ./enabled

echo --------
echo With Exceptions and RTTI Disabled
du disabled -b
time ./disabled
