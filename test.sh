# #!/bin/bash

# needs shuf command
# if [ $# -ne 1 ]; then
#     exit 1
# fi

# ARG=$(seq -2147483648 2147483647 | shuf -n $1 | tr '\n' ' ')
# ./push_swap $ARG | ./checker_OS $ARG
# echo "operations $(./push_swap $ARG | wc -l)"

# always works
#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number_of_values>"
    exit 1
fi

generate_numbers() {
    count=$1
    numbers=""
    used=()
    while [ $(echo "$numbers" | wc -w) -lt $count ]; do
        num=$((RANDOM % 4294967295 - 2147483648))
        used=0
        for used_num in $numbers; do
            if [ "$used_num" -eq "$num" ]; then
                used=1
                break
            fi
        done
        if [ $used -eq 0 ]; then
            numbers="$numbers $num"
        fi
    done
    echo $numbers
}

ARG=$(generate_numbers $1)
./push_swap $ARG | ./checker_OS $ARG
echo "operations $(./push_swap $ARG | wc -l)"
