#/bin/bash

echo "The build script to create branches and tags for new release from upstream."
echo "The first argument is the upstream tag name."
echo "Second optional argument is the build number, e.g. b1"
echo "Usage: ./build.sh v5.4.0"

#INPUT VARIABLES
uptag="$1"
[ "$2" ] && bn="$2" || bn="b1"
branch_name="build-${uptag:1}"
tag_name="$uptag-$bn"

#CONFIGURATION VARIABLES
build_branch="main-build"

echo "Checkout the tag from upstream"
git checkout tags/$uptag

echo "Create a new brach for editing"
git checkout -b $branch_name || git checkout $branch_name
# If the branch already exists, checkout that branch and copy the latest Github action scripts

echo "Copy the Github actions from build branch"
[ ! -d .github/workflows ] && mkdir -pv .github/workflows
for i in bin nightly
do
    action_yml=".github/workflows/build-$i.yml"
    git show $build_branch:$action_yml > $action_yml
    echo "Copied $action_yml"
done

echo "Commit the changes"
git add .github/workflows/*.yml
git commit -m "Added the build actions"

echo "Push to Github"
git push origin $branch_name

echo "Create a tag for release and push to Github"
git tag $tag_name
git push --tags

echo "Done. Please check the Github action results on the website."
git checkout $build_branch
echo "Switched back to build branch"
