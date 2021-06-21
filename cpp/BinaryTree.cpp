#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorderprint(struct node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}

void inorderprint(struct node* root){
    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
void postorderprint(struct node* root){
    if(root==NULL){
        return;
    }

    postorderprint(root->left);
    postorderprint(root->right);
    cout<<root->data<<" ";
}

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node* BuildTreepre_and_in(int preorder[],int inorder[],int start,int end){
    if(start>end)
        return NULL;
    
    static int idx=0;
    int curr=preorder[idx];
    idx++;
    node* nde=new node(curr);
    if(start==end){
        return nde;
    }
    int pos=search(inorder,start,end,curr);
    nde->left=BuildTreepre_and_in(preorder,inorder,start,pos-1);
    nde->right=BuildTreepre_and_in(preorder,inorder,pos+1,end);

    return nde;
}

node* BuildTreepost_and_in(int postorder[],int inorder[],int start,int end){
    if(start>end)
        return NULL;

    static int idx=4;
    int curr=postorder[idx];
    idx--;
    node* nde=new node(curr);
    if(start==end){
        return nde;
    }
    int pos=search(inorder,start,end,curr);
    nde->left=BuildTreepost_and_in(postorder,inorder,start,pos-1);
    nde->right=BuildTreepost_and_in(postorder,inorder,pos+1,end);

    return nde;
}

void printLevelOrder(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* nde=q.front();
        q.pop();
        if(nde!=NULL){
            cout<<nde->data<<" ";
            if(nde->left){
                q.push(nde->left);
            }
            if(nde->right){
                q.push(nde->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }        
    }
}

int sumAtk(node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node* nde=q.front();
        q.pop();
        if(nde!=NULL){
            if(level==k){
                sum+=nde->data;
            }
            if(nde->left){
                q.push(nde->left);
            }
            if(nde->right){
                q.push(nde->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }        
    }
    return sum;
}

int sumAll(node* root){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    while(!q.empty()){
        node* nde=q.front();
        q.pop();
        if(nde!=NULL){
            sum+=nde->data;
            if(nde->left){
                q.push(nde->left);
            }
            if(nde->right){
                q.push(nde->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }        
    }
    return sum;
}

int numberofnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return numberofnodes(root->left)+numberofnodes(root->right)+1;
}

int sumofallnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return sumofallnodes(root->left)+sumofallnodes(root->right)+root->data;
}

int calcheight(node* root){
    if(root==NULL){
        return 0;
    }
    return max(calcheight(root->left),calcheight(root->right)) + 1;
}

int calculatediameter(node* root,int *height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldiameter=calculatediameter(root->left,&lh);
    int rdiameter=calculatediameter(root->right,&rh);
    int currentdiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currentdiameter,max(ldiameter,rdiameter));
}

void sumreplace(node* root){
    if(root==NULL){
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
}

bool isbalanced(node* root,int *height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(isbalanced(root->left,&lh)==false){
        return false;
    }
    if(isbalanced(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}

void rightview(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}

void leftview(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }

}

node* findlca(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* left=findlca(root->left,n1,n2);
    node* right=findlca(root->right,n1,n2);
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(left!=NULL){
        return findlca(root->left,n1,n2);
    }
    if(right!=NULL){
        return findlca(root->right,n1,n2);
    }
}

int finddist(node* root,int k,int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }

    int left=finddist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return finddist(root->right,k,dist+1);
}

int disbtwnodes(node* root,int n1,int n2){
    node* lca=findlca(root,n1,n2);
    int d1=finddist(lca,n1,0);
    int d2=finddist(lca,n2,0);

    return d1+d2;
}

void flattenabinarytree(node* root){
    if(root==NULL || (root->right==NULL && root->left==NULL)){
        return;
    }
    if(root->left!=NULL){
        flattenabinarytree(root->left);
        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flattenabinarytree(root->right);
}

void printsubtreenodes(node* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printsubtreenodes(root->left,k-1);
    printsubtreenodes(root->right,k-1);
}

int printnodesatk(node* root,node* target,int k){
    if(root==NULL){
        return-1;
    }
    if(root==target){
        printsubtreenodes(root,k);
        return 0;
    }

    int dl=printnodesatk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->right,k-dl-2);
        }
        return 1+dl;
    }

    int dr=printnodesatk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}

bool getpath(node* root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getpath(root->left,key,path) || getpath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(node* root,int n1,int n2){
    vector<int> path1,path2;
    if(!getpath(root,n1,path1) || !getpath(root,n2,path2)){
        return-1;
    }
    int pc;
    for(pc=0;pc<path1.size() && path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}

node* LCA2(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node* leftLCA=LCA2(root->right,n1,n2);
    node* rightLCA=LCA2(root->right,n1,n2);
    if(rightLCA && leftLCA){
        return root;
    }
    if(leftLCA!=NULL){
        return leftLCA;
    }

    return rightLCA;

}

int maxpathsumutil(node* root,int &ans){
    if(root==NULL){
        return 0;
    }

    int left=maxpathsumutil(root->left,ans);
    int right=maxpathsumutil(root->right,ans);
    int nodemax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodemax);
    int singlepathsum=max(root->data,max(root->data+left,root->data+right));
    return singlepathsum;
}

int maxpathsum(node* root){
    int ans=INT_MIN;
    maxpathsumutil(root,ans);
    return ans;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    // preorderprint(root);
    // cout<<"\n";
    // inorderprint(root);
    // cout<<"\n";
    // postorderprint(root);
    // int inorder[]={4,2,1,5,3};
    // int preorder[]={1,2,4,3,5};
    // int postorder[]={4,2,5,3,1};
    // node* root=BuildTreepre_and_in(preorder,inorder,0,4);
    // node* root1=BuildTreepost_and_in(postorder,inorder,0,4);
    // inorderprint(root);
    // inorderprint(root1);
    // printLevelOrder(root);
    // int s=sumAll(root);
    // cout<<s;
    // cout<<numberofnodes(root)<<" "<<sumofallnodes(root);
    // cout<<calcheight(root);
    // int height=0;
    // cout<<calculatediameter(root,&height);
    // sumreplace(root);
    // preorderprint(root);
    // int height=0;
    // if(isbalanced(root,&height)){
    //     cout<<"yes";
    // }
    // else{
    //     cout<<"No";
    // }
    // rightview(root);
    // leftview(root);
    // cout<<disbtwnodes(root,4,7)<<endl;
    // printnodesatk(root,root->left,1);
    // flattenabinarytree(root);
    // inorderprint(root);
    // cout<<endl;
    // cout<<LCA(root,4,7)<<endl;
    // node* LCA=LCA2(root,4,7);
    // cout<<LCA->data<<endl;
    cout<<maxpathsum(root)<<endl;
    return 0;
}

