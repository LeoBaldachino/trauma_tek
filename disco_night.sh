# Reverse the screen orientation
xrandr -o inverted

# Set the background to a disco ball
feh --bg-fill https://preview.redd.it/wz80jkhcp6z61.jpg?auto=webp&s=e86693b09c01d9c784d500668106232ec7160294

# fuck up gamma and contrast
while true; do
    xrandr --output eDP-1 --gamma $((RANDOM % 1000)):$((RANDOM % 1000)):$((RANDOM % 1000)) --brightness $((RANDOM % 1000)) --contrast $((RANDOM % 1000))
    sleep 0.1
    xrandr --output eDP-1 --gamma 0.5:0.5:0.5 --brightness 1
    sleep 0.1
done
