# Git Practice

A refresher for anyone who has used Git before, or for people who want to learn in a safe space. This isn't the only way to use Git, but it's the way that I do it, so it's probably the best.

<details>
    <summary id="Workflow-overview">Workflow overview</summary>

## Workflow overview

We will step through each of these points below. But this is a rough side by side difference of working with SVN versus the Git equivalence I am about to cover.

<table>
<tr>
<th>SVN</th>
<th>Git</th>
</tr>

<tr>
<td>checkout repo</td>
<td>
fork repo<br>
clone your fork<br>
add all team members as remotes
</td>
</tr>

<tr>
<td>svn update</td>
<td>
git fetch --all<br>
git checkout main<br>
git merge blessed/main
</td>
</tr>

<tr>
<td>(write lots of code)</td>
<td>
git checkout -b PROJ-1234_TaskTitle<br>
(write some code)<br>
git commit ...<br>
(write some more code)<br>
git commit ...<br>
(repeat)
</td>
</tr>

<tr>
<td>svn commit</td>
<td>
git push<br><br>
pull request<br>
someone reviews and approves<br>
merge pull request
</td>
</tr>

</table>

</details>

---

<details>
    <summary id="Set-up-your-project">Set up your project</summary>

## Set up your project

First, you need a GitHub account. If you haven't got one, create one now. For the username we will be using the naming convention: \<firstname\>\<surname\>AH e.g. `RichardSteeleAH`.

Go to: https://github.com/rich-Steele/GitPractice (If you're reading this already, open it in a new window so you can follow along.)

In the top right you'll see **Watch**, **Fork**, and **Star**. Click **Fork**, then accept using the green **Create Fork** button.

You should now be on the URL: https://github.com/<YOUR_NAME>/GitPractice

This is *your* copy of the repository. A **fork** is a personal copy of someone else's project. It acts as a bridge between the original repo and your own, allowing you to open **Pull Requests** with your changes. Forking provides a healthy boundary between your work and the central project.

Next, click the green **Code** button and (with HTTPS selected) copy the clone link.

---

Now we set things up on your machine.

Go to wherever you want this project to live on your PC. It doesn't matter where, mine is in: C:\Users\Richard.Steele

Right-click → **Git Bash Here**, then type `git clone` then right-click and paste the link you copied before. It should look like this:

```
git clone https://github.com/<YOUR_NAME>/GitPractice.git
```

Press return. This downloads the repo to your computer.

Move into the folder:

```
cd GitPractice
```

---

Next, add me as a remote. This simply means tracking someone else's fork.

Check your current remotes:

```
git remote
```

You'll see only `origin`. This is what Git calls *your* repo.

Add me:

```
git remote add blessed https://github.com/rich-Steele/GitPractice.git
```

Check again:

```
git remote
````

You should now see `origin` and `blessed`.

> A blessed, or canonical, repository is one which has the approval of the managers of the project. The blessed repository is supposed to be the de facto standard where all other clones are made from. If there is one place where code should be correct, it is the blessed repository.

For Allen & Heath work, this will be the `Allen-Heath` repository that you create your fork from.

You can and should add other team members as remotes too. You will need the URL of their forks. To find people's forks, on GitHub go to the **blessed repo** (for this example: https://github.com/rich-Steele/GitPractice) → click **Fork** → **View existing forks**. You'll see all users who have forked the project. Copy their link, or click through to their fork and copy the URL from the browser URL bar. Add them using the `git remote add` command followed by *(nickname or alias)* *(their fork URL)*

```
# Example until he sets one up
git remote add Max https://github.com/MaxEllisAH/GitPractice.git
```

Then check it has been added with `git remote`. Repeat for all people working on the project that you want visibility of.

To see or check the full fork paths use:
```
git remote -v
```

Almost done.

---

Lastly, you are currently on the **main** branch. This is **bad**. Do not work in `main`. Do not be in your `main` branch for long. `main` is your important, stable branch. Not a working branch. It should match other people's `main` and the blessed repo's `main`. It is the single source of truth in your repository.

Note that historically this was called `master` however the convention has recently changed. You will see Git veterans mix it up still although the meaning is the same.

Check your branches:

```
git branch
```

To create and switch to a new safe working branch:

```
# `-b` creates a new branch from your current state, WorkingBranch is a name I made up, make your own up if you want

git checkout -b WorkingBranch
```

Check again with:

```
git branch
```

You should see both branches, with your working branch highlighted.

Done.

</details>

---

<details>
  <summary id="A-nicer-git-environment">A nicer git environment</summary>

## A nicer git environment

Viewing Git as a **graph** or **tree** is the best way to understand branches and merges. There are many tools (Git GUI, GitKraken, TortoiseGit, etc.) but the one I recommend is the **Git Graph** extension in VS Code. Even if you are familiar with TortoiseSVN then you are familiar with how rubbish it can be. So now is a good time to start using something better.

Install Git Graph:

1.  In VS Code, open the Extensions panel (four squares icon)
2.  Search for **Git Graph**
3.  Install it

Now open your repo's folder in VS Code:

**File → Open Folder → GitPractice**

Open the Source Control sidebar (three circles with lines). In the top bar you'll see an icon with vertical lines and dots **View Git Graph**.

The other useful control here is the **Show Remote Branches** toggle to display or hide branches from your remotes.

I strongly recommend keeping a VS Code window open with Git Graph even if you code in another IDE. If you go to the top menu bar and click **Terminal → New Terminal** then you get a window below to type in Git commands.

Finally set up your Git identity:

```
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

</details>

---

<details>
  <summary id="Check-it-all-works">Check it all works</summary>

## Check it all works

In your cloned repo are a few files. Let's make a simple change and commit it.

### Typical workflow

-   Make a branch
-   Write code
-   Commit
-   Write more code
-   Commit
-   Repeat
-   Push
-   Open Pull Request

Note the differences to SVN here.

Firstly, we always work in a branch. These are lightweight, quick, and easy to make unlike SVN. They are not a new copy of the repo, but mark a jumping off point for a new set of changes to be made away from your important main/master branch.

Commits are purely to your local git instance. Many commits are made when working on a task.

Push is when you send your changes to GitHub. You can do this as often as you like, it will only update your fork. The central repo will not be affected or even notified, and all your work in progress is then backed up on GitHub instead of solely on your hard drive.

Pull Request is the final step to merge your changes into the central repository (blessed)

---

In the repo are some files. Go to `MathLib.cpp` and you can see the function is incomplete. We will fix it.

First we will checkout and move into a new branch:
```
git checkout -b MATH-0001_FixAddFunction
```

Change line 5 from `return 0;` to `return A + B;` and save. Next we will commit the change.

### Commit

A commit saves your changes *locally*. Commit early, commit often, and you won't ever risk losing work. You can and should commit multiple times per task. Get used to it. It is a brilliant safety net compared to one large bundled up commit like SVN.

Using VS Code:

1.  Make changes and save the file
2.  Open the Source Control panel
3.  Review changes before staging
4.  Stage files using the **+** icon
5.  Write a meaningful commit message
6.  Click the ✓ to commit

A good commit message is important. Avoid things like "WIP" or "fixed bug".

In step 3 above when using VS Code, clicking on each file will bring up a traditional diff. Use this opportunity to remove any unnecessary changes e.g. extra new lines or whitespace.

CLI equivalent:

```
git diff
git add path/to/file
# or to stage everything
git add -A

git commit -m "My descriptive commit message"
```

Feel free to make another change and commit that too. You should be comfortable making multiple commits while on a task.

### Push

This sends your branch to your GitHub fork:

```
git push
```

The first time, Git will tell you to set the upstream. This is the place where Git is trying to push your changes to. GitHub doesn't yet know about your new branch. Nicely though, it tells you what to type to fix this. Copy what it says and press Enter (instead of `--set-upstream` you can also use the shorthand `-u`).

```
git push -u origin <branchName>
```

After that, `git push` is enough.

Similar to commits, you should get used to pushing often. Keeping GitHub up to date with your changes has no downsides. It does not affect the central repo, and if your computer dies overnight then everything is still stored safely and securely on GitHub. That only happens with Pull requests.

### Pull Request

A Pull Request (PR) asks to merge your changes into the blessed repo. Often if you are quick enough after pushing then GitHub will give you a notification about the branch and suggest that you pull request. Otherwise go to your fork on GitHub → switch to your branch → **New Pull Request**.

Give it:

-   A sensible title. This should be the Jira ticket ID and title.
-   A good description
   + If working from a jira ticket, add a link to the ticket here
   + If you have made good commit messages so far, this can often be a collection or summary of just those commit messages
-   Check the "Files changed" tab

Submit it. Now anyone can review it, comment, request changes, or approve. When working on project we can request reviewers on the PR page, word of mouth, or simply by seeing which PRs are currently pending. I have left a PR pending at https://github.com/rich-steele/GitPractice/pulls. Go there and leave a comment on it. Approve it if you think it's ready to merge in.

PR review is normal and healthy. It is how quality is maintained.

Once approved by someone, it is your responsibility to merge in your own pull request. You will have recieved an email when your PR is approved with a link to the PR itself. Go there and click merge. Now blessed/main has your changes.

The branch you were working on has served it's purpose and you can delete it.

```
# to remove just your local branch leaving the one on GitHub intact

git branch -d <BranchName>

# To remove both your local and upstream branch on GitHub

git branch -D <BranchName>
```

Note you cannot delete a branch that you are currently in, so create and move to a different one. Not `main`... Get in the habit of leaving that one alone.

Also, Git will warn you if you are about to delete a branch with unmerged changes. Which is brilliant and has saved many lives.

</details>

---

<details>
  <summary id="Updating">Updating</summary>

## Updating

To keep your repo up to date with blessed:

```
git fetch --all
git checkout main
git merge blessed/main
```

Now your `main` matches the canonical version.

Remember don't stay in `main`. Either create a new branch:

```
git checkout -b MyNewBranch
```

or update an existing one:

```
git checkout WorkingBranch
git merge main
```

Git is far better at merging than SVN. This is part of the reason that we are migrating to it. Merging will be a regular and easy process.

</details>

---

<details>
  <summary id="Branch-switching">Branch switching</summary>

## Branch switching

Creating and switching between branches is incredibly easy and useful with git. It allows you to make and save changes to files, then change to a different task with entirely different code changes if the first task becomes blocked, or you are required to switch to a different feature.

I'll walk through a quick demonstration.

Open your graph/tree visual representation to follow where your position in it changes.

First move to where your main branch is and checkout a new branch:
```
git checkout main
git checkout -b DEMO_HelloWorld
```

Open *StringLib.cpp* and add a comment in the constructor that says "Hello World!"
```
#include "StringLib.h"

StringLib::StringLib()
{
    // Hello World!
}
```

Save and commit the change as before. Notice in your graph view how the commit has been added at the top.

Move back to where your main branch is and checkout a new branch:
```
git checkout main
git checkout -b DEMO_FrenchHelloWorld
```

Notice the tree view. Your previous commit is still at the top, but your active highlighted position is now in the new branch at the same position as main.

As before add a comment to *StringLib.cpp* in the constructor that says "Bonjour le monde!"
```
#include "StringLib.h"

StringLib::StringLib()
{
    // Bonjour le monde!
}
```

Save and commit the change as before. Notice in your graph view how the commit has been added at the top, but on a seperate path from the HelloWorld branch, both branching from main.

With *StringLib.cpp* open, use git to switch back and forth between the branches you have just created. The file will change, the highlighted position in the tree view will change. It's quick, easy, and safe.

```
git checkout DEMO_HelloWorld

# See the file change to show "Hello World!"

git checkout DEMO_FrenchHelloWorld

# See the file change to show "Bonjour le monde!"
# Repeat as much as you like
```

These branches are now pointless so you can delete them as before
  
</details>

---

<details>
  <summary id="What-comes-next">What comes next?</summary>

## What comes next?

Our GitHub organisation is secure and private. You'll need to be added to the appropriate team by your line manager.

You will also **not** use HTTPS for cloning internal repos. We use **SSH keys**. Add one now.

To generate a key:

```
# Generate a key and save it to the default location

ssh-keygen -t ed25519 -C "<your GitHub email address>"
```

View your public key:

```
cat ~/.ssh/id_ed25519.pub
```

Copy the entire output.

Add the key to GitHub:

1.  Go to https://github.com/settings/keys
2.  Click **New SSH key**
3.  Paste your public key into **Key**
4.  Give it a meaningful title e.g. dLive VM
5.  Click **Add SSH key**

Test:

```
ssh -T git@github.com
```

After you are added to the project team, when you go to clone the repo use SSH and the link will look like this:

```
git@github.com:Allen-Heath/<RepoName>.git
```

Clone as before:
```
git clone git@github.com:Allen-Heath/<RepoName>.git
```

Note you will need to set up new key per machine. Expect to have separate keys for your Windows pc and each of your virtual machines.

Let me know if you run into any problems.

Rich

</details>

---
<details>
  <summary id="Cheat-sheet">Cheat sheet</summary>

## Cheat sheet

There are many commands Git can use. But these are enough for anyone to use Git effectively. More complicated commands exist but you shouldn't need to use them. If something goes wrong and those functions are required then someone with experience should use them.

---

Show current status of your branch, e.g. changed or staged files:
```
git status
```

List all local branches:
```
git branch
```

Switch to an existing branch:
```
git checkout BRID-1234_MyBranchName
```

Create and switch to a new branch:
```
git checkout -b BRID-1235_MyNewBranchName
```

Update your repo from blessed:
```
git fetch --all
git checkout main
git merge blessed/main

# Don't stay in main

git checkout BRID-1234_MyBranchName

# Bring your branch up to date

git merge main
```

Stage files (although I recommend using a GUI interface):
```
git add path/to/file
```

Commit:
```
git commit -m "This is my sensible commit message"
```

Push:
```
git push
```

Add a remote
```
git remote add <name> <fork URL>
```

</details>

---
<details>
  <summary id="Advanced-comparison">Advanced comparison</summary>

## Git vs SVN Command Comparison

| Action / Purpose                     | Git Command                                   | SVN Command                                |
|--------------------------------------|-----------------------------------------------|--------------------------------------------|
| Check out / clone a repository       | `git clone <url>`                             | `svn checkout <url>`                       |
| See current status                   | `git status`                                  | `svn status`                               |
| Add a file                           | `git add <file>`                              | `svn add <file>`                           |
| Commit changes                       | `git commit -m "message"`                     | `svn commit -m "message"` (or `svn ci`)    |
| View history                         | `git log`                                     | `svn log`                                  |
| Update from remote                   | `git pull`                                    | `svn update` (or `svn up`)                 |
| Push changes                         | `git push`                                    | *(N/A SVN commits go directly to server)*  |
| Revert file to last commit           | `git checkout -- <file>`                      | `svn revert <file>`                        |
| Show differences                     | `git diff`                                    | `svn diff`                                 |
| Create a branch                      | `git checkout -b <branch>`                    | `svn copy trunk branches/<branch>`         |
| Switch branch                        | `git checkout <branch>`                       | `svn switch <branch-url>`                  |
| Merge a branch                       | `git merge <branch>`                          | `svn merge <branch-url>`                   |
| View branches                        | `git branch`                                  | `svn list <repo>/branches`                 |
| Delete a branch                      | `git branch -d <branch>`                      | `svn delete <repo>/branches/<branch>`      |
| View remote repos                    | `git remote`                                  | *(N/A SVN uses a single central repo)*     |
| Stash changes                        | `git stash`                                   | *(N/A no stash in SVN)*                    |
| Undo last commit (keep changes)      | `git reset --soft HEAD~1`                     | *(SVN does not support this. Only reverse commits)* |
| Undo last commit (discard changes)   | `git reset --hard HEAD~1`                     | `svn merge -c -REV .` then commit          |

^ Be very careful with that last one. It will throw away committed work. Don't use it. I left it there so you know to avoid it.

Similarly, Git will generally reject a command that will cause a conflict or act destructively. `-f` may force that change but please don't use this. There is likely a conflict somewhere that requires attention. Don't force changes.

(Thanks for the table ChatGPT)

</details>
