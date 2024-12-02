docker run -it \
	--rm \
	--name test_jinja \
	--mount type=bind,source="$(pwd)",target=/srv \
	python3-jinja2

