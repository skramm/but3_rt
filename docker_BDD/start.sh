docker network create bddnet

docker run \
	--name bddserver \
	--network=bddnet \
	--rm \
	-e MYSQL_ROOT_PASSWORD=secret \
	-d \
	-p 3306:3306 \
	mysql:5.7

# options
# --rm: suppression conteneur après son arrêt
# -d: exécution en mode "detached"

	
	
