#!/bin/bash
echo "Press 'q' to exit"
echo "press any key to run the next test."
read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run test.cub, a basic cub file, should run correctly.\n"
./cub3D srcs/maps/test.cub
echo "Press 'q' to exit\n"
fi
read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run all_sprites_floor.cub, should run correctly.\n"
./cub3D srcs/maps/all_sprites_floor.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run col_valid255_0.cub, should run correctly.\n"
./cub3D srcs/maps/col_valid255_0.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run double_input.cub, should error.\n"
./cub3D srcs/maps/double_input.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run empty_file.cub, should error.\n"
./cub3D srcs/maps/empty_file.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run huge_map.cub, should run or throw a warning.\n"
./cub3D srcs/maps/huge_map.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run invalid_map_doubles.cub, should error.\n"
./cub3D srcs/maps/invalid_map_doubles.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run invalid_map_noise.cub, should error.\n"
./cub3D srcs/maps/invalid_map_noise.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run invalid_map_noise2.cub, should error.\n"
./cub3D srcs/maps/invalid_map_noise2.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run invalid_map_noise3.cub, should error.\n"
./cub3D srcs/maps/invalid_map_noise3.cub
echo "Press 'q' to exit\n"
fi
fi
read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run invalid_map_notclosed.cub, should error.\n"
./cub3D srcs/maps/invalid_map_notclosed.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run invalid_rgb_input.cub, should error.\n"
./cub3D srcs/maps/invalid_rgb_input.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run lo dev.cub, should work.\n"
./cub3D srcs/maps/invalid_lo\ dev.cub
printf "Run lo dev.cub, should work.\n"
./cub3D "srcs/maps/invalid_lo dev.cub"
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run lo\ dev.cub, should work.\n"
./cub3D srcs/maps/invalid_lo\\\ dev.cub
printf "Run lo dev.cub, should work.\n"
./cub3D "srcs/maps/invalid_lo\ dev.cub"
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run map_none.cub, should error.\n"
./cub3D srcs/maps/map_none.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run not_a_cub_file.cu, should error.\n"
./cub3D srcs/maps/not_a_cub_file.cu
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run map_opendiag.cub, should error.\n"
./cub3D srcs/maps/map_opendiag.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run map_opensp.cub, should error.\n"
./cub3D srcs/maps/map_opensp.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run negative_input.cub, should error.\n"
./cub3D srcs/maps/negative_input.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run only_spawn.cub, should run.\n"
./cub3D srcs/maps/only_spawn.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run res_neg.cub, should error.\n"
./cub3D srcs/maps/res_neg.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run res_overfl.cub, should run.\n"
./cub3D srcs/maps/res_overfl.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run res_zero.cub, should run.\n"
./cub3D srcs/maps/res_zero.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run small_res.cub, should run.\n"
./cub3D srcs/maps/small_res.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run spaces_in_path.cub, should run.\n"
./cub3D srcs/maps/spaces_in_path.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run valid_map_noise.cub, should run.\n"
./cub3D srcs/maps/valid_map_noise.cub
echo "Press 'q' to exit\n"
fi
fi
read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run xpm_test.cub, should run.\n"
./cub3D srcs/maps/xpm_test.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run this_cub_does_not_exist.cub, should error.\n"
./cub3D srcs/maps/this_cub_does_not_exist.cub
echo "Press 'q' to exit\n"
fi

read -n 1 k <&1
if [[ $k = q ]] ; then
printf "\nQuitting from the program\n"
break
else
printf "Run lodev.cub --save, should run.\n"
./cub3D srcs/maps/lodev.cub --save
W=`file ./screen.bmp | cut -f 7 -d " "` #width
H=`file ./screen.bmp | cut -f 9 -d " "` #height
if [W != "16384" && H != "500"] then
printf "The screenshot is not the right size\n"
else
printf "screenshot is the correct size"
fi
echo "Press 'q' to exit\n"
fi

done